mv door_managment_fi door_managment_files
mkdir door_configuration door_map door_log
door_managment_files % mv *.conf door_configuration
door_managment_files % mv *.log door_logs
door_managment_files % mv *.1 door_map
chmod +x ai_door_control.sh
bash ai_door_managment_module.sh
