# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/)
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

Legacy AmiFTP versions use major.revision numbering (e.g. 1.11 > 1.1, 1.201 > 1.20).

## [2.0] - (amigazen project release)

### Added
- FTP: Support for passive data connections (`PASV`) with active (`PORT`) fallback for better compatibility with NAT and firewalled environments.
- FTP: Support for extended passive/active commands (`EPSV`/`EPRT`) to prepare for IPv6 and modern server setups.
- FTP: Capability discovery via `FEAT` (e.g. `SIZE`, `MDTM`, `EPSV`, `PASV`, `UTF8`) to drive conditional use of optional protocol features.
- workbench.library v45: launch viewer in Workbench mode via `OpenWorkbenchObject()` when available.
- Default Sitelist entries for Aminet and EAB.

### Changed
- Socket I/O: Align `bsdsocket.library` usage with the AmigaOS 3.2 SDK by correctly initialising `struct sockaddr_in` (including `sin_len`) before `connect()` and related calls.
- Socket I/O: Clarified and standardised handling of network byte order for ports, ensuring all `sin_port` assignments use `htons()` when values originate from URLs or user input.
- FTP: Prefer PASV/EPSV data connections by default when available, retaining a configurable fallback to legacy PORT mode.
- FTP: Improved parsing of `150` replies and optional use of `SIZE`/`MDTM` replies (`213`) for transfer progress, resume support, and timestamp handling.
- FTP: Centralised reply code classification (1xx/2xx/3xx/4xx/5xx) to simplify and standardise error handling paths.
- GUI: Improved window title and screen title information
- Build: Is now compatible with NDK 3.2 R4
- MainWindow: default size 70% of screen when no saved setting exists.
- FTP URL parsing: case-insensitive handling of `ftp://` protocol.
- Log messages follow syslog-style conventions; improved error logging around DOS I/O failures using `IoErr()`.
- Default config when no prefs file exists: buttons and toolbar visible (`mp_ShowButtons` / `mp_ShowToolBar` TRUE).

### Fixed
- Socket I/O: Ensured type correctness for length arguments (`socklen_t` and related pointers) in `getpeername()`, `getsockname()`, `bind()`, `accept()`, and `setsockopt()` calls to match SDK prototypes.
- FTP: Hardened line-oriented parsing and buffer handling in `getreply()`, directory listing (`next_remote_line()`), and related helpers with strict bounds checks and guaranteed NUL termination.
- FTP: Replaced unsafe `vsprintf()` usage in FTP command construction with bounded formatting to avoid buffer overflows on long inputs.
- FTP: Corrected or removed unsafe `s_fgets()` behaviour (double increment, incorrect newline detection); LIST/NLST line reads bounded.
- FTP: Bounded writes to `response_line` and `str_buf` for protection against long server lines and oversized commands.
- FTP: Clarified and fixed control/data connection state transitions, timeouts, and cleanup after errors or `ABOR` so that sockets and internal state remain consistent.
- Connect window: now shows URL host when connecting via URL, not last site in list (bugreports/mh.txt).
- Help file location corrected.
- rtasl.lib integration and crash on connection open; rtasl version of reqtools headers to avoid collision with original headers.
- Transfer abort handling kept responsive via the transfer window.
- Dirlist: do not add 0-byte files with 255-character name (listbrowser display bug); NULL `name` check in `add_direntry()`.
- Upload: remote path for STOR is now `remote/FilePart(entry->name)` when a remote directory is set, avoiding creation of unwanted directories (remotepath/dirtree fix).
- UploadFile: NULL checks for list entry and `entry->name`; check `malloc` result for ADT rem buffer.
- Hotlist crash when adding a new entry: SiteWindow cursor-up/cursor-down and double-click guard against NULL `sn` from listbrowser UserData; `flags=0UL` instead of `flags=NULL`; `retnode` checked before use.
- Window position reset when only hotlist changed: CloseMainWindow updates MainPrefs from the window when ConfigChanged so exit saves the correct position.
- Transferwindow in aminet/ADT mode: OpenTransferWindow no longer assumes MainWindow is non-NULL; positions transfer window at screen center when main window is not open.

### Removed
- AsyncIO dependency; AmigaDOS I/O used directly instead.
- AS225 / socket.library support; single binary uses bsdsocket.library only.
- reqtools.library dependency; requesters and UI use Reaction/Intuition instead.
- Legacy async I/O and related dependencies; simplified socket and transfer handling.

### Security
- FTP: Reduced risk from malicious or malformed server replies by adding strict buffer limits and more defensive reply parsing throughout the control and data paths.
- FTP: Avoided accidental exposure of credentials or sensitive data in logs by tightening command/response handling and documenting best practices for future FTPS work.

## [1.843] - 1997-09-29

### Added
- "Send raw ftp-command" in the Project menu.
- "Rename" in the Files menu.
- "Create dir" in the Files menu.
- Doubled maximum length of the ADT pattern string to 512 characters.

### Fixed
- ARexx: GETATTR FILELIST and MGET; GET issues reported for follow-up.

### Changed
- Corrected errors in AmiFTP.guide.

## [1.814] - 1996-12-14

### Added
- "Overwrite all" button in the requester when a file already exists.

### Fixed
- Window size is now saved correctly.

## [1.801] - 1996-11-30

### Fixed
- Filerequester bug in the global preferences window (affected some systems).

## [1.797] - 1996-11-06

### Added
- Speedbar and preferences to toggle speedbar and normal buttons.
- All button actions duplicated as menu items.
- Cursor-key scrolling in the file list (Shift/Alt for page/top/bottom).
- "Select by pattern" in the Files menu (AmigaDOS pattern).
- AmiFTP starts even if no TCP/IP stack is running.

### Fixed
- HELP sometimes required two presses to open online help.
- Progress bar bug.
- Recompiled with SAS/C 6.57.

### Changed
- ClassAct no longer included in the archive; obtain from ftp.warped.com/pub/amiga/classact/.
- Not all language catalogs updated for this release.

## [1.607] - 1996-07-01

### Added
- NewIcon-style icon (Phil Vedovatti) and KMI-style dock icon (Heikki Kantola).

### Fixed
- Enforcer hit when pressing cursor-up in the sitelist with no selection (regression from 1.594).
- Sitelist window sometimes impossible to close (ClassAct-related); behaviour changed to avoid it.

### Known issues
- Due to a bug in penmap.image, AmiFTP does not work on AmigaOS 2.x until penmap.image is fixed.

## [1.594] - 1996-06-18

### Added
- Main window title shows selected file count, total bytes, and free space on the download device.
- CLI/startup: connect via `ftp://[user@]host[:port][/path]` or `[user]@host[:port][/path]`; same syntax in the "Current site" gadget. Single vs double slash in path (e.g. `host/pub/amiga` vs `host//pub/amiga`) distinguishes relative vs absolute path.

### Fixed
- Minor bugs.

## [1.541] - 1996-06-05

### Fixed
- Aminet-mode sometimes downloading each file twice; "Get readme" option buggy.
- Group window incorrectly same as site window.
- Enforcer hit when iconified during a transfer.

### Added
- Installer script localisation (English and Spanish; works best with AT Installer v43).

## [1.530] - 1996-05-27

### Added
- Aminet-mode: browse RECENT list and see new files since last visit; define site with Aminet checked and remote directory `/pub/aminet/` (upload in Aminet-mode planned for a later version).
- Greek catalog (Pantelis Kopelias).
- ARexx FTPCOMMAND always sets RC2 to the FTP server status number; other ARexx commands set RC2 on server error.
- Delete menu command now deletes directories (where server allows).
- Sorting mode saved in preferences when saving from Settings/Save.

### Fixed
- Abort when connecting now closes the connect window.
- Abort routine in the Transfer window.
- Sitelist cursor-key movement (enforcer hits).
- Reorganized global settings window (close gadget = Cancel).

### Changed
- New layout in the Transfer window.

## [1.264] - 1996-03-09

### Added
- Mailing list for new-version announcements (lilja@lysator.liu.se; one-way, no discussion).
- Group feature in the sitelist (submenus in the hotlist). Sort removed for now.

### Fixed
- Possible memory leak.
- Menus losing state after putting the main window to sleep.

## [1.199] - 1996-02-19

### Added
- ARexx: `FTPCOMMAND COMMAND/F` to send a string directly to the server (e.g. `FTPCOMMAND RMD test`).

### Fixed
- Better error reporting when a library cannot be opened.
- GETATTR enforcer hit when proxy server was not specified.

## [1.151] - unreleased

### Fixed
- ARexx View command was viewing the wrong file.

### Added
- find.amiftp (Aminet search script by Sami Itkonen) added to the archive.

## [1.149] - 1996-02-11

### Added
- Support for both AmiTCP and AS225r2/I-Net 225 in one binary; AS225 CLI/tooltype to force socket.library; default is bsdsocket.library then socket.library.
- Iconify main window during transfer (iconify gadget in Transfer window; uniconify via gadget or double-click on icon).
- ARexx: `VIEW ASCII/S,BIN/S,FILE/A` (download to T: and spawn viewer; file deleted on quit).
- SETATTR option `QUIET/K` (QUIET=TRUE: no requesters, ConnectWindow closes on failure; QUIET=FALSE: normal; GETATTR STEM=foo, foo.QUIET).
- Icelandic catalog (Sigurbjörn B. Lárusson).
- Spanish catalog (José Roberto González Rocha).

### Fixed
- ARexx SETATTR LOCALDIR=foo now updates the Download dir gadget.
- ARexx GETATTR STEM=bar (uppercase variable recognition).
- Enforcer hits when opening on a non-existent public screen.

### Changed
- "Show dot-files?" moved to Settings menu.

### Known issues
- AS225r2/I-Net 225: connection can break when aborting; under investigation.

## [1.14] - 1996-01-24

### Added
- CLI/tooltype `FILEFONT` for main listview font (e.g. `AmiFTP FILEFONT foo.font/8`).

### Fixed
- Busy pointer when deleting files.
- Flicker when selecting items in the main window and sitelist.
- Fuel gauge now has 10 intervals instead of 9.

### Changed
- Updated installer script.

## [1.0] - 1995-12-17

### Added
- First Aminet release.

### Fixed
- Bug in sitelist window.

### Changed
- `AmiFTP sitename` (e.g. `AmiFTP ftp.luth.se`) from command line works again.
- AmiFTP.prefs search order: Current directory, PROGDIR:, ENVARC:, ~user/.
- AmiFTP no longer requires amigaguide.library to run (online help still needs it).
- All catalogs updated.

## [0.1299]

### Added
- Reload gadget to re-read current directory from server.
- Alphabetical sorting of sitenames.

### Changed
- AmiFTP tries to determine correct filesize for links when transferring (TransferWindow shows correct size; filelist may show link size). Danish and German catalogs unchanged (see WWW page for updates).

## [0.1261b]

### Fixed
- Corrected gadget/image versions in archive (replaced accidentally included old versions from 0.1261).

## [0.1261]

### Changed
- AmiFTP should work on 68000/010 with the new gadgets/images in this archive.

## [0.1258]

### Fixed
- Hotlist menu now updates when a new preferences file is loaded or when sitelist is edited.

### Known issues
- May not work on 68000/010; feedback requested if it works on 000/010.

## [0.1235]

### Changed
- Moved from gadtools GUI to ClassAct GUI. ClassAct (C) Phantom Development. Ensure existing ClassAct gadgets are at least as new as those in this archive.
- Likely works with AmigaOS 2.x (not fully verified). Few new features compared to 0.864.

## [0.864]

### Added
- Get entire directory trees (e.g. cd to /pub on an Aminet site, select aminet dir, press Get).
- Primitive log window (CON:); toggle via Settings/Log window.
- Project/Add current to sitelist.
- Online help (HELP opens AmiFTP.guide in AmigaGuide).
- Default download directory.

## [0.776]

### Fixed
- Download handled filenames longer than 32 characters correctly.
- View handles filenames with spaces.
- FIXEDFONTNAME/SIZE argument.

### Changed
- Saving settings via menu also saves window size and position.

### Added
- ARexx DELETE; GETATTR FILELIST switch returns current filelist in STEM variable.

## [0.699]

### Fixed
- CPS cleared after each file uploaded.

### Changed
- AmiFTP-as225 should work with mlink (verified by author).

## [0.691]

### Fixed
- Links no longer View-ed twice.
- Workaround for V39 gadtools.library bug so Transfer Window looks correct on V39.
- Bytes transferred and CPS update count corrected. Minor fixes (DEBUG output removed).

## [0.664]

### Fixed
- Multiple-file download: files unmarked after transfer.
- Abort gadget in Transfer window no longer ghosted after first file.

### Added
- SETATTR USERNAME/PASSWORD from ARexx.

## [0.648]

### Added
- Transfer mode switch from menu (Binary/ASCII); default BINARY.
- PROPFONTNAME/PROPFONTSIZE and FIXEDFONTNAME/FIXEDFONTSIZE tooltypes/CLI for fonts (GUI uses screen proportional font except file listview).

### Fixed
- Various small fixes.

## [0.535]

### Fixed
- SETTINGS tooltype/CLI argument works again (broken in 0.533).

## [0.533]

### Added
- Resume transfer when downloading; Overwrite/Resume/Cancel when file exists.
- Settings menu: load/save settings, edit hotlist, Global (old preferences).
- Prefs search order: Current directory, PROGDIR:, ENV:, ~user/. Default when saving: PROGDIR:.
- Localisation.
- Password gadget for non-anonymous login.

## [0.348]

### Fixed
- SiteList window gadgets layout.

## [0.345]

### Added
- AmiFTP clones path when started from Workbench.
- Window size and position remembered when iconifying.
- Directory cache (up to ten dirs); Directory string gadget reads from server, not cache.
- mlink version (separate archive; cannot abort file transfers): AmiFTPmlink.lha.
- Delete remote files via menu (with confirmation).
- Select all / Unselect all in menu.
- Links shown with (link) in listview.
- ARexx upload (PUT/MPUT).

### Fixed
- Minor layout bugs.

## [0.275]

### Added
- ARexx port (not all functions implemented yet).
- View: download to T: and delete files on quit.

