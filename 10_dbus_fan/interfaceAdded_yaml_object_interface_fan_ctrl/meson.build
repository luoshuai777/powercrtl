# use to create a fanctrl interface
subdir('xyz/openbmc_project/fanctrl')

executable(
  'fan_ctrl_speed',
  'main_server.cpp',
  fanctrl_cpp,
  fanctrl_hpp,
  dependencies: [
    sdbusplus_dep,
    phosphor_logging_dep,
  ],
  implicit_include_directories: true,
  install: true
)

