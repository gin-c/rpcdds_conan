from conans import ConanFile, tools, CMake


class RpcddsConan(ConanFile):
    name = "rpcdds"
    version = "1.2"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    description = "rpcdds"
    url = "None"
    license = "None"
    author = "None"
    topics = None
    requires = "fast-dds/2.3.4@jm/release", "BoostThreadpool/0.2.5@jm/release"
    generators = "cmake", "virtualenv", "cmake_find_package"

    _cmake = None
    
    def source(self):
        git = tools.Git()
        git.clone("https://gitlab.upuphone.com/meng.jiao/rpcdds_conan.git", "master")
        
    def package(self):
        cmake = self._configure_cmake()
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = tools.collect_libs(self)

    def build(self):
        cmake = self._configure_cmake()
        cmake.build()

    def configure(self):
        pass

    def _configure_cmake(self):
        if self._cmake:
            return self._cmake
        self._cmake = CMake(self)
        self._cmake.definitions["RPCPROTO"] = "rpcdds"
        self._cmake.definitions["WITH_FASTRTPS"] = True
        self._cmake.definitions["BUILD_SHARED_LIBS"] = self.options.shared
        self._cmake.definitions["COMPILE_EXAMPLES"] = False
        self._cmake.configure()
        return self._cmake

