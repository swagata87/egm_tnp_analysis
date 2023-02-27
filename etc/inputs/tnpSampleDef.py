from libPython.tnpClassUtils import tnpSample

### qll stat
#eosDir1 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v1/'
#eosDir2 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v2/'
#eosDirREC = 'eos/cms/store/group/phys_egamma/tnp/80X/RecoSF/RECOSFs_2016/'
#eosWinter17 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/Moriond17_v1/'
eosMoriond18 = '/eos/cms/store/group/phys_egamma/swmukher/ntuple_2017_v2/'
eosRun3 = '/eos/cms//store/group/phys_egamma/tnpTuples/bjoshi/2023-02-01/2022/'

Moriond18_94X = {
    ### MiniAOD TnP for IDs scale factors
    'DY_1j_madgraph'              : tnpSample('DY_1j_madgraph',
                                       eosMoriond18 + 'DY1JetsToLLM50madgraphMLM.root',
                                       isMC = True, nEvts =  -1 ),
#    'DY_amcatnlo'                 : tnpSample('DY_amcatnlo',
#                                       eosMoriond18 + 'DYJetsToLLM50amcatnloFXFX.root',
#                                       isMC = True, nEvts =  -1 ),
    'DY_amcatnloext'                 : tnpSample('DY_amcatnloext',
                                       eosMoriond18 + 'DYJetsToLLM50amcatnloFXFXext.root',
                                       isMC = True, nEvts =  -1 ),


    'data_Run2017B' : tnpSample('data_Run2017B' , eosMoriond18 + 'RunB.root' , lumi = 4.793 ),
    'data_Run2017C' : tnpSample('data_Run2017C' , eosMoriond18 + 'RunC.root' , lumi = 9.753),
    'data_Run2017D' : tnpSample('data_Run2017D' , eosMoriond18 + 'RunD.root' , lumi = 4.320 ),
    'data_Run2017E' : tnpSample('data_Run2017E' , eosMoriond18 + 'RunE.root' , lumi = 8.802),
    'data_Run2017F' : tnpSample('data_Run2017F' , eosMoriond18 + 'RunF.root' , lumi = 13.567),

    }


Run3Prelim_126X = {
        'DY_1j_madgraph'    : tnpSample('DY_1j_madgraph', eosRun3 + '/mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8_2022_DY_LO.root', isMC=True, nEvts = 27310302),
        'DY_1j_madgraph_postEE'    : tnpSample('DY_1j_madgraph_postEE', eosRun3 + '/mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8_2022_DY_LO_postEE.root', isMC=True, nEvts = 96505000),
        'data_Run2022B': tnpSample('data_Run2022B', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022B.root', lumi = 0.09536),
        'data_Run2022C': tnpSample('data_Run2022C', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022C.root', lumi = 4.1821),
        'data_Run2022E': tnpSample('data_Run2022E', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022E.root', lumi = 5.1127),
        'data_Run2022F': tnpSample('data_Run2022F', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022F.root', lumi = 15.7633),
        'data_Run2022G': tnpSample('data_Run2022G', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022G.root', lumi = 2.9711)
    }

Run3Prelim_126X_preEE = {
        'DY_1j_madgraph'    : tnpSample('DY_1j_madgraph', eosRun3 + '/mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8_2022_DY_LO.root', isMC=True, nEvts = 27310302),
        'data_Run2022BC': tnpSample('data_Run2022BC', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022BC.root', lumi = 4.2775),
    }

Run3Prelim_126X_postEE = {
        'DY_1j_madgraph_postEE'    : tnpSample('DY_1j_madgraph_postEE', eosRun3 + '/mc/TnPTree_DYJetsToLL_M-50_TuneCP5_13p6TeV-madgraphMLM-pythia8_2022_DY_LO_postEE.root', isMC=True, nEvts = 96505000),
        'data_Run2022EFG': tnpSample('data_Run2022EFG', eosRun3 + '/data/TnPTree_EGamma_2022_Run2022EFG.root', lumi = 23.8471),
        }
