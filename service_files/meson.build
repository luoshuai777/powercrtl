unit_files = [
    'xyz.openbmc_project.power_ctrl.service'
    'host_power_state_check.service'
]

foreach u : unit_files
    configure_file(
        copy: true,
        input: u,
        install: true,
        install_dir: systemd_system_unit_dir,
        output: u,
        )
endforeach
