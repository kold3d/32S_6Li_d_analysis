#comma se p run list
#run_list = "040,041,042"
run_list = "028"
#file name on hdfs
file_name = "hdfs://gr-gmaster.tamu.edu:9000//data/run0715a/tree/run0715_{{{0}}}*_t.root".format(run_list)
