import ROOT
import worker
from pyspark import StorageLevel, SparkFiles, SparkContext, SparkConf
from runlist import file_name

if __name__ == "__main__" :
    #setup cluster
    sconf = SparkConf().setAppName("MDMAnalysis")
    sconf.set("spark.mesos.coarse", "false")
    sc = SparkContext(conf=sconf)

    sc.addFile("libMDM_test_analysis.so")
    sc.addFile("param.in")
    sc.addFile("rayin.dat")

    lines = sc.newAPIHadoopFile(file_name,"edu.tamu.hadoop.RootInputFormat",
                                "org.apache.hadoop.io.IntWritable","org.apache.hadoop.io.Text")
    histArrays = lines.map(lambda x : worker.analyze(x)).collect()

    for histArray in histArrays[1:] :
      for i in range(0,len(histArray)) :
	histArrays[0][i].Add(histArray[i])
     
    outFile = ROOT.TFile("out.root","recreate")
    for hist in histArrays[0] :
      hist.Write()
    outFile.Close()
