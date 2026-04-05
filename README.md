# AmiFTP 2

GUI FTP client for Amiga with ReAction, ARexx support, and Aminet mode.

## [amigazen project](http://www.amigazen.com)

*A web, suddenly*

*Forty years meditation*

*Minds awaken, free*

**amigazen project** is using modern software development tools and methods to update and rerelease classic Amiga open source software. Projects include a new AWeb, AmiFTP, Amiga Python 2, and the ToolKit project – a universal SDK for Amiga.

Key to the amigazen project approach is ensuring every project can be built with the same common set of development tools and configurations, so the ToolKit project was created to provide a standard configuration for Amiga development. All *amigazen project* releases will be guaranteed to build against the ToolKit standard so that anyone can download and begin contributing straightaway without having to tailor the toolchain for their own setup.

The original author of AmiFTP, Magnus Lilja, is not affiliated with the amigazen project. This software is redistributed under the terms in LICENSE.md (MIT License).

The amigazen project philosophy is based on openness:

*Open* to anyone and everyone – *Open* source and free for all – *Open* your mind and create!

PRs for all projects are gratefully received at [GitHub](https://github.com/amigazen/). While the focus now is on classic 68k software, it is intended that all amigazen project releases can be ported to other Amiga-like systems including AROS and MorphOS where feasible.

## About AmiFTP

AmiFTP is a full featured easy-to-use GUI FTP file transfer client for Amiga.

This project brings AmiFTP up to date so it builds against the NDK 3.2 and can continue to be updated and enhanced into the future.

## Features

- **Reaction GUI** – Native Amiga UI (Reaction/ClassAct).
- **Aminet mode** – Browse RECENT list, see new files since last visit, optional readme download.
- **ARexx interface** – Scriptable via ARexx port (GETATTR, SETATTR, CONNECT, DISCONNECT, CD, LCD, GET, MGET, PUT, MPUT, VIEW, FTPCOMMAND, etc.).
- **Resume transfer** – Resume interrupted downloads when the local file is shorter than the remote.
- **Multiselect** – Tag multiple files for upload or download.
- **Directory cache** – Caches recent directories for faster navigation.
- **Hotlist with submenus** – Sitelist with groups and quick-connect hotlist.
- **PASV / PORT** – Passive data connections with active PORT fallback for varied servers and networks.
- **Bounded I/O** – Safer reads of listings and server lines; improved transfer progress parsing.
- **ASL requesters** – File and path requesters use _asl.library_; AmiFTP 2 uses the _rtasl.lib_ link library to map reqtools.library is not required at runtime.

## Requirements

- **AmigaOS 3.2** with ReAction, or possibly older versions with ClassAct.
- **TCP/IP stack** providing **bsdsocket.library** only, no more AS225 socket.library support

## Version History

### Version 2
- **TCP/IP stack:** _AS225_ _socket.library_ disabled; _bsdsocket.library_ only.
- **I/O enhancements:** _AsyncIO_ removed; AmigaDOS I/O and improved abort/error handling.
- **UI enhancements:** connect window shows URL host; window title shows full ftp:// URL when connected, screen title shows selection and free space; sensible default window size; directory-cache Chooser fix.
- **FTP protocol:** Bounded buffers/lines, PASV with PORT fallback, safer LIST / 150 / SIZE handling, case-insensitive **ftp://** parsing.
- **Stability:** Fixes from version 1.953 (hotlist, transfer window placement, NULL site node, config save edge cases, etc.).

See **[CHANGELOG.md](CHANGELOG.md)** for full version history and **[TODO.md](TODO.md)** for possible future improvements.

## Frequently Asked Questions

### What is AmiFTP?

AmiFTP is a graphical FTP client for Amiga. You connect to FTP sites, browse directories, and transfer files with a native Reaction-based interface. It supports anonymous and authenticated logins, directory caching, a sitelist with groups, and an ARexx port for scripting.

### Why update AmiFTP for 2026?

The original AmiFTP depended on ClassAct (separate distribution), **reqtools.library**, **AsyncIO**, and multiple TCP stacks (AmiTCP, AS225, mlink, etc.). AmiFTP 2 drops **AsyncIO**, avoids **reqtools.library** at runtime by using **rtasl.lib**, and disables **AS225**. PASV, PORT fallback, and stricter parsing improve behaviour with modern servers and networks.

amigazen project is releasing new versions of AWeb, the Amiga web browser, and AmiFTP is the perfect partner for a full featured, Amiga native file transfer client.

### Can I contribute?

Yes. Code, testing, documentation, and translations are welcome and will remain under the **MIT License** (retain copyright and permission notices as in **LICENSE.md**). See the repository and [amigazen project](https://github.com/amigazen/) for how to submit pull requests.

## Contact

- **GitHub:** https://github.com/amigazen/amiftp/
- **Web:** http://www.amigazen.com/ (Amiga browser compatible)
- **amigazen:** aweb@amigazen.com

## Acknowledgements

*Amiga* is a trademark of **Amiga Inc**.

Original AmiFTP by **Magnus Lilja**, released to the open source community.
