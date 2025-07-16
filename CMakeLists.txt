project(CFE_DS C)
# This file is from https://github.com/cfs-apps/proxy_ds

include_directories(fsw/inc)
include_directories(fsw/src)

aux_source_directory(fsw/src APP_SRC_FILES)
aux_source_directory(fsw/tables APP_TABLE_FILES)

# Create the app module
add_cfe_app(ds ${APP_SRC_FILES})
add_cfe_tables(ds ${APP_TABLE_FILES})

