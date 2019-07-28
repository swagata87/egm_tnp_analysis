from libPython.tnpClassUtils import tnpSample

### qll stat
#eosDir1 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v1/'
#eosDir2 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v2/'
#eosDirREC = 'eos/cms/store/group/phys_egamma/tnp/80X/RecoSF/RECOSFs_2016/'
#eosWinter17 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/Moriond17_v1/'
eosMoriond18 = '/eos/cms/store/group/phys_egamma/swmukher/UL/ntuple_2017_UltraLegacy/'

Moriond18_94X = {
    ### MiniAOD TnP for IDs scale factors
    'DY_1j_madgraph'              : tnpSample('DY_1j_madgraph',
                                       eosMoriond18 + 'mc.root',
                                       isMC = True, nEvts =  -1 ),
#    'DY_amcatnlo'                 : tnpSample('DY_amcatnlo',
#                                       eosMoriond18 + 'DYJetsToLLM50amcatnloFXFX.root',
#                                       isMC = True, nEvts =  -1 ),
#    'DY_amcatnloext'                 : tnpSample('DY_amcatnloext',
#                                       eosMoriond18 + 'DYJetsToLLM50amcatnloFXFXext.root',
#                                       isMC = True, nEvts =  -1 ),


#    'data_Run2017B' : tnpSample('data_Run2017B' , eosMoriond18 + 'RunB.root' , lumi = 4.793 ),
    'data_Run2017C' : tnpSample('data_Run2017C' , eosMoriond18 + 'UL_RunC.root' , lumi = 0.785),
#    'data_Run2017D' : tnpSample('data_Run2017D' , eosMoriond18 + 'RunD.root' , lumi = 4.320 ),
#    'data_Run2017E' : tnpSample('data_Run2017E' , eosMoriond18 + 'RunE.root' , lumi = 8.802),
    'data_Run2017F' : tnpSample('data_Run2017F' , eosMoriond18 + 'UL_RunF.root' , lumi = 1.485),

    }
