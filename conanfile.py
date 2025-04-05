from conan import ConanFile
from conan.tools.cmake import CMake, CMakeToolchain, CMakeDeps, cmake_layout
from conan.tools.files import copy
import os


class UltraIrcConan(ConanFile):
    name = "ultra-ircd"
    version = "8.3.0"
    description = "Ultra-IRCd - Advanced IRC daemon"
    license = "GPL-2.0-or-later"
    homepage = "https://github.com/paige/ultra-ircd"
    url = "https://github.com/paige/ultra-ircd"
    settings = "os", "compiler", "build_type", "arch"
    options = {
        "shared": [True, False],
        "fPIC": [True, False],
        "with_tls": [True, False],
        "with_jansson": [True, False],
        "with_xml": [True, False],
    }
    default_options = {
        "shared": False,
        "fPIC": True,
        "with_tls": True,
        "with_jansson": True,
        "with_xml": True,
    }

    def config_options(self):
        if self.settings.os == "Windows":
            del self.options.fPIC

    def configure(self):
        if self.options.shared:
            self.options.rm_safe("fPIC")

    def requirements(self):
        if self.options.with_tls:
            self.requires("openssl/3.2.1")
        if self.options.with_jansson:
            self.requires("jansson/2.14")
        if self.options.with_xml:
            self.requires("libxml2/2.12.3")

    def layout(self):
        cmake_layout(self)

    def generate(self):
        tc = CMakeToolchain(self)
        tc.variables["WITH_TLS"] = self.options.with_tls
        tc.variables["WITH_JANSSON"] = self.options.with_jansson
        tc.variables["WITH_XML"] = self.options.with_xml
        tc.generate()

        deps = CMakeDeps(self)
        deps.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def package(self):
        cmake = CMake(self)
        cmake.install()
        licenses_dir = os.path.join(self.package_folder, "licenses")
        copy(self, "COPYING.md", src=self.source_folder, dst=licenses_dir)
        copy(self, "AUTHORS.md", src=self.source_folder, dst=licenses_dir)

    def package_info(self):
        self.cpp_info.libs = ["ircd-hybrid"]
        if self.settings.os in ["Linux", "FreeBSD"]:
            self.cpp_info.system_libs = ["dl", "m"] 