powerctrl_hpp = custom_target(
    'server.hpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.source_root() / '10_dbus_powerctrl/interfaceAdded_yaml_object_interface_power_ctrl',
        'interface',
        'server-header',
        'xyz.openbmc_project.powerctrl',
    ],
    input: '../powerctrl.interface.yaml',
    install: true,
    install_dir: get_option('includedir') / 'xyz/openbmc_project/powerctrl',
    output: 'server.hpp',
)

powerctrl_cpp = custom_target(
    'server.cpp',
    capture: true,
    command: [
        sdbuspp,
        '-r', meson.source_root() / '10_dbus_powerctrl/interfaceAdded_yaml_object_interface_power_ctrl',
        'interface',
        'server-cpp',
        'xyz.openbmc_project.powerctrl',
    ],
    input: '../powerctrl.interface.yaml',
    output: 'server.cpp',
)
