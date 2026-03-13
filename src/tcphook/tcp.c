/*
 * TCP stack abstraction: only bsdsocket.library (AmiTCP/Roadshow) is used.
 * AS225/socket.library support is commented out; use NDK SANA+RoadshowTCP-IP API.
 */
#include <proto/exec.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "tcphooks.h"

struct hostent *(*tcp_gethostbyname)(const UBYTE *name);
struct servent *(*tcp_getservbyname)(const UBYTE *name, const UBYTE *proto);
char * (*tcp_getlogin)(void);
struct passwd *(*tcp_getpwnam)(const char *name);
void (*tcp_endpwent)(void);
LONG (*tcp_gethostname)(STRPTR hostname, LONG size);

ULONG (*tcp_inetaddr)(const UBYTE *);
LONG (*tcp_socket)(LONG domain, LONG type, LONG protocol);
LONG (*tcp_ioctl)(LONG fd, ULONG request, char *argp);
LONG (*tcp_connect)(LONG s, const struct mysockaddr_in *name);
LONG (*tcp_waitselect)(LONG nfds,  fd_set *readfds, fd_set *writefds, fd_set *exeptfds,
		       struct timeval *timeout, ULONG *maskp);
LONG (*tcp_getpeername)(LONG s, struct sockaddr *name, LONG *namelen);
LONG (*tcp_closesocket)(LONG d);
LONG (*tcp_getsockname)(LONG s, struct sockaddr *name, LONG *namelen);
LONG (*tcp_setsockopt)(LONG s, LONG level, LONG optname, void *optval, LONG optlen);
LONG (*tcp_send)(LONG s, const UBYTE *msg, LONG len, LONG flags);
LONG (*tcp_recv)(LONG s, UBYTE *buf, LONG len, LONG flags);
LONG (*tcp_bind)(LONG s, const struct sockaddr *name, LONG namelen);
LONG (*tcp_listen)(LONG s, LONG backlog);
LONG (*tcp_accept)(LONG s, struct sockaddr *addr, LONG *addrlen);
LONG (*tcp_shutdown)(LONG s, LONG how);

/* AS225/socket.library support commented out; only bsdsocket.library is used.
int Setup225Hooks(void);
void Shutdown225(void);
*/
int SetupAmiTCPHooks(void);

/* SockBase used only when AS225 path is enabled (commented out). */
struct Library *SockBase;
struct Library *SocketBase=NULL;
struct Library *UserGroupBase=NULL;

/* Last failure reason when OpenTCP() returns 0; used for diagnostic. */
static char _open_tcp_fail_reason[96];

const char *OpenTCPFailureReason(void)
{
    return _open_tcp_fail_reason;
}

int OpenTCP(BOOL UseAS225)
{
    /* AS225/socket.library path disabled; always use bsdsocket.library (AmiTCP/Roadshow). */
    _open_tcp_fail_reason[0] = '\0';
    /*
    {
	char *as="inet:libs/socket.library";
	if (UseAS225) {
	    SockBase=OpenLibrary(as,4L);
	    if (!SockBase)
		return 0;
	    if (!Setup225Hooks())
		return 0;
	}
	else {
    */
    SocketBase=OpenLibrary("bsdsocket.library",2);
    if (!SocketBase) {
	strcpy(_open_tcp_fail_reason, "bsdsocket.library (v2) open failed - not in LIBS: or wrong version?");
	return 0;
    }
    /* usergroup.library is optional (e.g. not provided by UAE); used for getlogin/getpwnam and errno context. */
    UserGroupBase=OpenLibrary("usergroup.library",1);
    if (!SetupAmiTCPHooks()) {
	strcpy(_open_tcp_fail_reason, "SetupAmiTCPHooks failed");
	return 0;
    }
    /*
	}
    }
    */
    return 1;
}

void CloseTCP(void)
{
    /* if (SockBase) { Shutdown225(); CloseLibrary(SockBase); } */
    if (SocketBase)
	CloseLibrary(SocketBase);
    if (UserGroupBase)
	CloseLibrary(UserGroupBase);
}
