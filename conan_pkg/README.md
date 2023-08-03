```
conan install . --install-folder=tmp/build --build=missing
CONAN_CPU_COUNT=10 conan build . --source-folder=.. --build-folder=tmp/build
conan package . --source-folder=.. --build-folder=tmp/build --package-folder=tmp/package
conan export-pkg . jm/testing --package-folder=tmp/package


conan test test_package pangolin/20200520@curt/testing

conan create . jm/testing -pr:b default -pr:h android_armv8.conan --build=missing

conan upload rpcdds/1.2@jm/testing --all -r=repo -c
conan upload "*" --all -r=repo -c
```

