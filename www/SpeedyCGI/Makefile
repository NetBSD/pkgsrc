# $NetBSD: Makefile,v 1.9 2008/06/12 02:14:54 joerg Exp $

DISTNAME=	CGI-SpeedyCGI-2.22
PKGNAME=	SpeedyCGI-2.22
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://daemoninc.com/SpeedyCGI/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://daemoninc.com/SpeedyCGI/
COMMENT=	Speed up perl scripts by running them persistently

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST= auto/CGI/SpeedyCGI/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
