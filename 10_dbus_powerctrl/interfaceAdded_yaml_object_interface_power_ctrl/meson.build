# use to create a powerctrl interface
subdir('xyz/openbmc_project/powerctrl')

executable(
  'powerctrl',
  'main_server.cpp',
  powerctrl_cpp,
  powerctrl_hpp,
  dependencies: [
    sdbusplus_dep,
    phosphor_logging_dep,
  ],
  implicit_include_directories: true,
  install: true
)

