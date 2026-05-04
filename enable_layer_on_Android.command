
adb push build/layersvt/libVkLayer_custom.so /data/user/0/com.YourCompany.Android_Test/
adb shell settings put global enable_gpu_debug_layers 1
adb shell settings put global gpu_debug_app com.YourCompany.Android_Test
adb shell settings put global gpu_debug_layers VK_LAYER_CUSTOM