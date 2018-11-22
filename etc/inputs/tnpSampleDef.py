from libPython.tnpClassUtils import tnpSample

### qll stat
#eosDir1 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v1/'
#eosDir2 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/v2/'
#eosDirREC = 'eos/cms/store/group/phys_egamma/tnp/80X/RecoSF/RECOSFs_2016/'
#eosWinter17 = 'eos/cms/store/group/phys_egamma/tnp/80X/PhoEleIDs/Moriond17_v1/'
#eosMoriond18 = '/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_01292018/Moriond18_V1/'
#eos2018Data_102X = '/eos/cms/store/group/phys_egamma/soffi/TnP/ntuples_20180920/2018Data_1/'
#eos2017Data_94X = '/eos/cms/store/group/phys_egamma/swmukher/ntuple_2017_v2/' #this is needed b/c we want to study the SF of 2018 data w.r.t. 2017 94X MC
#eos2017Data_94X_ForRecoSF = '/eos/cms/store/group/phys_egamma/swmukher/tnp/ID_V2_2017/'
eos2018Data_102X_EcalNoiseFix_200kRelVal = '/eos/cms/store/group/phys_egamma/swmukher/rereco2018/ECAL_NOISE/'

Data2018_102X = {
    ### MiniAOD TnP for IDs scale 

    'DY_MG'              : tnpSample('DY_MG',
                                            eos2018Data_102X_EcalNoiseFix_200kRelVal + 'DYJetsToLLmadgraphMLM.root',
                                            isMC = True, nEvts =  -1 ),

    'DY_powheg'              : tnpSample('DY_powheg',
                                            eos2018Data_102X_EcalNoiseFix_200kRelVal + 'DYToEEpowheg.root',
                                            isMC = True, nEvts =  -1 ),
    

    'data_Run2018A' : tnpSample('data_Run2018A' , eos2018Data_102X_EcalNoiseFix_200kRelVal + 'RunA.root' , lumi = 10.723),  

    'data_Run2018B' : tnpSample('data_Run2018B' , eos2018Data_102X_EcalNoiseFix_200kRelVal + 'RunB.root' , lumi = 5.964),

    'data_Run2018C' : tnpSample('data_Run2018C' , eos2018Data_102X_EcalNoiseFix_200kRelVal + 'RunC.root' , lumi = 6.382),

#    'data_Run2018Dv2' : tnpSample('data_Run2018Dv2' , eos2018Data_102X_EcalNoiseFix_200kRelVal + 'data/Prompt2018_RunD_v2.root' , lumi = 24.1), 


    }



##about lumi: thse ntuples are done with /afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/PromptReco/Cert_314472-321221_13TeV_PromptReco_Collisions18_JSON.txt = with recorded luminosity : 31.71 /fb but ~20% are crashed. Also we need to update the single runs lumi


 
