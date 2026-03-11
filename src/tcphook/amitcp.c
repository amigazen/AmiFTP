/*
 * AmiTCP/bsdsocket.library hook layer using the API defined in
 * SDK NDK SANA+RoadshowTCP-IP (proto/bsdsocket.h, proto/usergroup.h).
 * Compile with IDIR pointing at SANA+RoadshowTCP-IP/netinclude.
 */
#include <proto/bsdsocket.h>
#include <proto/usergroup.h>

#include <utility/tagitem.h>
#include <sys/ioctl.h>

#include "tcphooks.h"

extern struct Library *SocketBase;
extern struct Library *UserGroupBase;
/* errno declared by netinclude sys/errno.h; do not redeclare. */
extern STRPTR _ProgramName;

struct hostent *amitcp_gethostbyname(const UBYTE *name)
{
    return (struct hostent *)gethostbyname((char *)name);
}

struct servent *amitcp_getservbyname(const UBYTE *name, const UBYTE *proto)
{
    return (struct servent *)getservbyname((char *)name, (char *)proto);
}

char *amitcp_getlogin(void)
{
    return (char *)getlogin();
}

struct passwd *amitcp_getpwnam(const char *name)
{
    return (struct passwd *)getpwnam(name);
}

void amitcp_endpwent(void)
{
    endpwent();
}

LONG amitcp_gethostname(STRPTR hostname, LONG size)
{
    return gethostname(hostname,size);
}

ULONG amitcp_inetaddr(const UBYTE *s)
{
    return inet_addr((char *)s);
}

LONG amitcp_socket(LONG domain, LONG type, LONG protocol)
{
    return socket(domain,type,protocol);
}

LONG amitcp_ioctl(LONG fd, ULONG request, char *argp)
{
    if (request==TCPFIONBIO)
	request=FIONBIO;
    else if (request==TCPFIOASYNC)
	request=FIOASYNC;
    return IoctlSocket(fd, request, argp);
}

LONG amitcp_connect(LONG s, const struct mysockaddr_in *sin)
{
    struct sockaddr_in hisctladdr;

    bzero((char *)&hisctladdr,sizeof(hisctladdr));
    hisctladdr.sin_family=sin->sin_family;
    hisctladdr.sin_addr.s_addr=sin->sin_addr.s_addr;
    hisctladdr.sin_port=sin->sin_port;

    return connect(s,(struct sockaddr *)&hisctladdr,sizeof(hisctladdr));
}

LONG amitcp_waitselect(LONG nfds,  fd_set *readfds, fd_set *writefds, fd_set *exeptfds,
		       struct timeval *timeout, ULONG *maskp)
{
    return WaitSelect(nfds, readfds,writefds,exeptfds,timeout,maskp);
}

LONG amitcp_getpeername(LONG s, struct sockaddr *name, LONG *namelen)
{
    return getpeername(s, name, (socklen_t *)namelen);
}

LONG amitcp_closesocket(LONG d)
{
    return CloseSocket(d);
}

LONG amitcp_getsockname(LONG s, struct sockaddr *name, LONG *namelen)
{
    return getsockname(s, name, (socklen_t *)namelen);
}

LONG amitcp_setsockopt(LONG s, LONG level, LONG optname, void *optval, LONG optlen)
{
    return setsockopt(s,level,optname,optval,optlen);
}

LONG amitcp_send(LONG s, const UBYTE *msg, LONG len, LONG flags)
{
    return send(s, (char *)msg, len, flags);
}

LONG amitcp_recv(LONG s, UBYTE *buf, LONG len, LONG flags)
{
    return recv(s,buf,len,flags);
}

LONG amitcp_bind(LONG s, const struct sockaddr *name, LONG namelen)
{
    return bind(s, (struct sockaddr *)name, (socklen_t)namelen);
}

LONG amitcp_listen(LONG s, LONG backlog)
{
    return listen(s,backlog);
}

LONG amitcp_accept(LONG s, struct sockaddr *addr, LONG *addrlen)
{
    return accept(s, addr, (socklen_t *)addrlen);
}

LONG amitcp_shutdown(LONG s, LONG how)
{
    return shutdown(s,how);
}

int SetupAmiTCPHooks()
{
    tcp_socket=amitcp_socket;
    tcp_bind=amitcp_bind;
    tcp_listen=amitcp_listen;
    tcp_accept=amitcp_accept;
    tcp_connect=amitcp_connect;
    tcp_send=amitcp_send;
    tcp_recv=amitcp_recv;
    tcp_shutdown=amitcp_shutdown;
    tcp_setsockopt=amitcp_setsockopt;
    tcp_getsockname=amitcp_getsockname;
    tcp_getpeername=amitcp_getpeername;
    tcp_ioctl=amitcp_ioctl;
    tcp_closesocket=amitcp_closesocket;
    tcp_waitselect=amitcp_waitselect;
    tcp_inetaddr=amitcp_inetaddr;
    tcp_gethostbyname=amitcp_gethostbyname;
    tcp_endpwent=amitcp_endpwent;
    tcp_getpwnam=amitcp_getpwnam;
    tcp_getlogin=amitcp_getlogin;
    tcp_gethostname=amitcp_gethostname;
    tcp_getservbyname=amitcp_getservbyname;

    if (ug_SetupContextTags(_ProgramName,
			    UGT_INTRMASK, SIGBREAKB_CTRL_C,
			    UGT_ERRNOPTR(sizeof(errno)), &errno,
			    TAG_END)!= 0)
      return 0;
    return 1;
}
