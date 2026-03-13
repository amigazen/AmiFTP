# AmiFTP

GUI FTP client for Amiga with Reaction, ARexx support, and Aminet mode.

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

This project brings AmiFTP up to date so it builds against the NDK 3.2 and take advantage of the latest  Amiga platforms: workbench.library support for launching the file viewer, Passive FDTP PASV/EPSV and improved FTP behaviour behind NAT/firewalls are all new features in AmiFTP 2.0

## Features

- **Reaction GUI** – Native Amiga UI (Reaction/ClassAct).
- **Aminet mode** – Browse RECENT list, see new files since last visit, optional readme download.
- **ARexx interface** – Scriptable via ARexx port (GETATTR, SETATTR, CONNECT, DISCONNECT, CD, LCD, GET, MGET, PUT, MPUT, VIEW, FTPCOMMAND, etc.).
- **Resume transfer** – Resume interrupted downloads when the local file is shorter than the remote.
- **Multiselect** – Tag multiple files for upload or download.
- **Directory cache** – Caches recent directories for faster navigation.
- **Hotlist with submenus** – Sitelist with groups and quick-connect hotlist.
- **Online AmigaGuide help** – Built-in documentation (AmiFTP.guide).
- **PASV / EPSV** – Passive and extended passive data connections with PORT fallback for NAT/firewall-friendly transfers.
- **FEAT and SIZE** – Capability discovery and size/date for transfer progress where the server supports it.

## Requirements

- **Amiga 3.2** or compatible (e.g. 3.1.4 with Reaction).
- **TCP/IP stack** providing `bsdsocket.library` (e.g. AmiTCP, Miami, or built-in stack on 3.2).
- **workbench.library** – For Workbench integration.
- **amigaguide.library** v36+ – For online help (optional; AmiFTP runs without it).

## Building

AmiFTP is built with **SAS/C** and **smake**; the project is set up to build against the ToolKit standard and NDK 3.2.

- Source and makefiles are under `src/amiftp/` (see `SMakefile`).
- Ensure the ToolKit (or equivalent NDK 3.2 + compiler setup) is installed and configured as expected by the makefile.
- Build instructions and any ToolKit-specific steps are documented in BUILD.md

## Version 2.0 and changelog

Version **2.0** (amigazen project release) modernises AmiFTP: Reaction GUI, removal of AS225 and reqtools.library, single binary with bsdsocket.library only, PASV/EPSV support, workbench.library support, and many stability and security fixes merged from the Amiga OS4 fork.

See [CHANGELOG.md](CHANGELOG.md) for full version history and [TODO.md](TODO.md) for possible future improvements.

## Documentation

- **AmiFTP.guide** – User and reference documentation (in the release package and under `src/amiftp/doc/` and `release/`).
- **LICENSE.md** – MIT License.

## Frequently Asked Questions

### What is AmiFTP?

AmiFTP is a graphical FTP client for Amiga. You connect to FTP sites, browse directories, and transfer files with a native Reaction-based interface. It supports anonymous and authenticated logins, directory caching, a sitelist with groups, and an ARexx port for scripting.

### Why update AmiFTP for 2026?

The original AmiFTP depended on ClassAct (separate distribution) and reqtools.library, and supported multiple TCP stacks (AmiTCP, AS225, mlink, etc.). Modern Amiga has Reaction built in and standardises on bsdsocket.library. Updating to Reaction and a single stack simplifies installation and keeps AmiFTP buildable and maintainable. PASV/EPSV and improved parsing make it work better with current servers and networks.

### Does AmiFTP work on Workbench 3.1?

Version 2.0 is built and tested for Amiga 3.2. It may run on 3.1.4 with Reaction; plain 3.1 would need Reaction (or ClassAct) and a bsdsocket.library stack. See the documentation for requirements.

### Can I contribute?

Yes. Code, testing, documentation, and translations are welcome and will remain under the MIT License. See the repository and [amigazen project](https://github.com/amigazen/) for how to submit pull requests.

## Contact

- **GitHub:** https://github.com/amigazen/amiftp/
- **Web:** http://www.amigazen.com/ (Amiga browser compatible)
- **amigazen:** aweb@amigazen.com

## Acknowledgements

*Amiga* is a trademark of **Amiga Inc**.

Original AmiFTP by **Magnus Lilja**, release to the open source community
