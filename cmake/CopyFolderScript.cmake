if(NOT COPY_SOURCE OR NOT COPY_DEST)
  message(FATAL_ERROR "COPY_SOURCE and COPY_DEST must be set.")
endif()

if(EXCLUDE_FILES)
  string(REPLACE "|" ";" EXCLUDE_FILES "${EXCLUDE_FILES}")
endif()

if(EXCLUDE_FOLDERS)
  string(REPLACE "|" ";" EXCLUDE_FOLDERS "${EXCLUDE_FOLDERS}")
endif()

message(STATUS "Copying from ${COPY_SOURCE} to ${COPY_DEST}")

if(CMAKE_HOST_WIN32)
  set(robocopy_args
    "${COPY_SOURCE}" "${COPY_DEST}"
    /S /MT /R:0 /W:0 /NP
  )

  if(EXCLUDE_FILES)
    list(APPEND robocopy_args /XF ${EXCLUDE_FILES})
  endif()

  if(EXCLUDE_FOLDERS)
    list(APPEND robocopy_args /XD ${EXCLUDE_FOLDERS})
  endif()

  execute_process(
    COMMAND robocopy.exe ${robocopy_args}
    RESULT_VARIABLE rc
  )

  if(rc GREATER 7)
    message(FATAL_ERROR "robocopy failed (exit code ${rc})")
  endif()
elseif(CMAKE_HOST_UNIX)
  set(rsync_args -av)

  foreach(pattern IN LISTS EXCLUDE_FILES)
    list(APPEND rsync_args "--exclude=${pattern}")
  endforeach()

  foreach(pattern IN LISTS EXCLUDE_FOLDERS)
    list(APPEND rsync_args "--exclude=${pattern}")
  endforeach()

  execute_process(
    COMMAND rsync ${rsync_args} "${COPY_SOURCE}/" "${COPY_DEST}/"
    RESULT_VARIABLE rs
  )

  if(rs GREATER 0)
    message(FATAL_ERROR "rsync failed (exit code ${rs})")
  endif()
else()
  message(FATAL_ERROR "Unsupported host platform for asset copying.")
endif()