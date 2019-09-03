#!/bin/bash

python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingVeto94XV2  --checkBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingVeto94XV2  --createBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingVeto94XV2  --createHist
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingVeto94XV2  --doFit
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingVeto94XV2  --sumUp

sleep 5

python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingLoose94XV2  --checkBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingLoose94XV2  --createBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingLoose94XV2  --createHist
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingLoose94XV2  --doFit
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingLoose94XV2  --sumUp

sleep 5

python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingMedium94XV2  --checkBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingMedium94XV2  --createBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingMedium94XV2  --createHist
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingMedium94XV2  --doFit
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingMedium94XV2  --sumUp

sleep 5

python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingTight94XV2  --checkBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingTight94XV2  --createBins
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingTight94XV2  --createHist
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingTight94XV2  --doFit
sleep 2
python tnpEGM_fitter.py etc/config/settings_ele.py --flag passingTight94XV2  --sumUp

