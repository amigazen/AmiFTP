# AmiFTP – possible future ideas

Reaction is the evolution of ClassAct (part of AmigaOS), so GUI ideas from the original ClassAct-era todo are still relevant.

---

## Possible future ideas

### Preferences / config
- Prefs: configurable number of directories in cache (from NextRelease).
- Prefs: "Delete viewed files on exit" option (from NextRelease).
- Prefs: UpdateGaugeRate (transfer gauge update rate).
- Prefs: Buffer size (transfer buffer).
- Prefs: Font preferences (proportional and fixed fonts for listview / rest of UI).
- Prefs: User-defined maximum number of dirs in cache.
- Longer pattern string for "hide Aminet dirs" (ADT pattern).
- Change location of preferences to ENV:AmiFTP directory

### UI / behaviour
- Clear "Current ftp-site" gadget after disconnect.
- ".." (parent directory) in the listview.
- Different sort algorithms (e.g. by size, by type).
- List directories first (or last) in file list.
- Highlight directories in the listview.
- Update "number of files" (and bytes selected, free space) while reading dir.
- Transfer window: show "x MB/KB left" or similar during transfer.
- More / clearer status messages (e.g. "Logging in...", connection steps).
- Center all windows above the main window (or consistent window positioning).
- ListBrowser layout: nest one level deeper with single child, REACTION_BackFill, LAYERS_BACKFILL (from original todo; Reaction/ClassAct GUI).

### Transfer
- Ask before overwriting existing files when transferring (if not already default).
- Skip instead of abort when transferring multiple files (skip one file, continue rest).
- Overwrite / Skip this file / Cancel transfer when file exists.
- Batch-get improvements (e.g. queue or batch behaviour).
- Ask server for size of links (SIZE command) for better progress.

### Menu / actions
- Select by pattern (from NextRelease; confirm if already in Menus).
- Tag/Untag all (if not already present).
- Sort sites (in sitelist / hotlist).
- Comments or notes for each site (in sitelist).

### Connection / site
- Set both host and directory before connecting (e.g. from URL or site string).
- Support `site:path` and `ftp://[user@]site[:port]/path` style input where missing.
- Reconnect (if not already present).

### ARexx
- GETATTR returning full filelist / dirlist (or extended FILELIST).
- STEM.aminetpath, STEM.aminetdescr (Aminet-related ARexx attributes).
- Tag/select files via ARexx.

### Other
- Log window improvements (if still CON:-only).
- Workbench path inheritance when launched from Workbench (if still an issue).

---

## Not going to do

Items that are obsolete, already implemented, or no longer relevant.

### Obsolete or removed
- Use AsyncIO (or "asyncio") routines for file transfer – AsyncIO dependency removed; AmigaDOS I/O used directly.
- TRSF_* enums as return codes from sendrequest() – internal implementation detail.
- Try NONBINDINGSOCKET / select() after connect – legacy socket approach; current code uses bsdsocket.library as standard.

### Already implemented (no longer TODO)
- Localize; on-line help; default viewer; Tooltype/CLI support; PORTNAME argument.
- OK/Cancel gadgets in Preferences; Delete function; RENAME; Makedir; Raw FTP command in menu; FTPCOMMAND in ARexx; DELETE via ARexx; ARexx VIEW; GETATTR FILELIST (or equivalent).
- Tag/Untag all; Select by pattern; Add current site to sitelist; Submenus in Hotlist (groups); Hide/show dot-files in Settings; Reconnect.
- Log window; SIZE for links (if already used for progress); Draw an icon.

### One-off / historical bug fixes (not future work)
- Fix double-click for ftp.aston.ac.uk; server.biologie.uni-erlangen.de empty dirs; rexxportname AmiFTP.0.1.2; HotList gadgets messed up; Transfer window appears twice when Get'ing links; Abort closing connect window; Activate subwindows only if main active; Parent->dir tagged Get disabled; Busy pointer when CD-ing or when deleting; "" when viewing files; timeout still thinking connected.
- "Permission denied" weird character; Update number of files while reading dir (if already done).

### 1990s-specific or low priority
- Bullets in password gadget; 'Reload' (if already present as Reload gadget); user/password requester when connecting via site-string gadget – keep only if still missing and desired.
- Specific server or site workarounds documented in old todo (e.g. cd to link behaviour) – document in FAQ or known issues instead of TODO.
