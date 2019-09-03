from libPython.tnpClassUtils import tnpSample

### qll stat
#eosDir1 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v1/'
#eosDir2 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v2/'
#eosDirREC = 'eos/cms/store/group/phys_egamma/tnp/80X/RecoSF/RECOSFs_2016/'
#eosWinter17 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/Moriond17_v1/'
Run3 = '/eos/cms/store/group/phys_egamma/swmukher/Run3_DYtoEE/JamboreeAug19/'
Run2 = '/eos/cms/store/group/phys_egamma/swmukher/rereco2018/ECAL_NOISE/'
Run3_bkg = '/eos/cms/store/group/phys_egamma/swmukher/Run3/JamboreeAug19/'
#eos2018Data_V1 = '/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_05122018/2018Data_V1/'
eos2018Data_V3 = '/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_06152018/2018Data_1/'
#Moriond18_94X 
Data2018_10_1_X= {
    ### MiniAOD TnP for IDs scale factors
#    'DY_run3'          : tnpSample('DY_run3',
#                                       Run3 + 'ttbar_semilep_2023.root',
#                                       Run3 + 'DYtoEE_2023_powheg.root',
#                                       isMC = True, nEvts =  -1 ),
    'DY_run2'          : tnpSample('DY_run2',
                                       Run2 + 'DYToEEpowheg.root',
                                       isMC = True, nEvts =  -1 ),
#    'DY_run2'          : tnpSample('DY_run2',
#                                       Run2 + 'TTToSemiLeptonicTuneCP5powhegpythia8.root',
#                                       isMC = True, nEvts =  -1 ),
#    'DY_madgraph_Moriond18' : tnpSample('DY_madgraph_Moriond18', 
#                                       Run3 + 'DYtoEE_2023_powheg.root',
#                                       isMC = True, nEvts =  -1 ),
#    'DY_amcatnlo_Moriond18' : tnpSample('DY_amcatnlo_Moriond18', 
#                                       Run3 + 'DYtoEE_2023_powheg.root',
#                                       isMC = True, nEvts =  -1 ),

#    'data_Run2017B' : tnpSample('data_Run2017B' , Run2 + 'DYToEEpowheg.root' , lumi = 1 ),
#    'data_2018_RunA_v123' : tnpSample('data_Run2017B' , Run2 + 'DYToEEpowheg.root' , lumi = 1 ),
     #'data_Run2017C' : tnpSample('data_Run2017C' , eosMoriond18 + 'data/TnPTree_17Nov2017_RunC.root' , lumi = 9.9 ),
     'data_2018' : tnpSample('data_2018' , eos2018Data_V3 + 'data/TnP_Prompt2018_RunB_v1_all_DUMMY.root' , lumi = 16.59 )
#    'data_Run2017D' : tnpSample('data_Run2017D' , eosMoriond18 + 'data/TnPTree_17Nov2017_RunD.root' , lumi = 4.36 ),
#    'data_Run2017E' : tnpSample('data_Run2017E' , eosMoriond18 + 'data/TnPTree_17Nov2017_RunE.root' , lumi = 9.53 ),
#    'data_Run2017F' : tnpSample('data_Run2017F' , eosMoriond18 + 'data/TnPTree_17Nov2017_RunF.root' , lumi = 13.96 ),

    }

#Data2018_10_1_X = {

#    'DY_madgraph'          : tnpSample('DY_madgraph',
#                                       eosMoriond18 + 'mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_all.root',
#                                       isMC = True, nEvts =  -1 ),
#    'DY_madgraph_2018_30p' : tnpSample('DY_madgraph_2018_30p',
#                                       eos2018Data_V3 + 'mc/TnP_DYJetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8_30pStat_all.root',
#                                       isMC = True, nEvts =  -1 ),
#    'DY_amcatnlo_2018' : tnpSample('DY_amcatnlo_Moriond18',
#                                       eosMoriond18 + 'mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8_all.root',
#                                       isMC = True, nEvts =  -1 ),

#    'data_2018_RunA_v123' : tnpSample('data_2018_RunA_v123' , eos2018Data_V3 + 'data/TnP_Prompt2018_RunA_v123_selectedRuns.root' , lumi = 0 ),#FIXME so far all the integrated value of the lumi is assigned to runb, still need to compute individual run lumi
#    'data_2018_RunB_v1' : tnpSample('data_2018_RunB' , eos2018Data_V3 + 'data/TnP_Prompt2018_RunB_v1_all.root' , lumi = 16.59 ),



#}
