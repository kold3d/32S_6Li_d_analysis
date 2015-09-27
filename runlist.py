#comma se p run list
#run_list = "040,041,042"
run_list = "023"
#file name on hdfs
file_name = "hdfs://gr-gmaster.tamu.edu:9000//data/run0915a/tree/run0915a_{{{0}}}*_t.root".format(run_list)
