# $NetBSD: Makefile,v 1.3 2000/01/04 18:06:32 bouyer Exp $
# FreeBSD Id: ports/textproc/textutils/Makefile,v 1.7 1999/09/18 17:46:30 steve Exp

DISTNAME=	textutils-2.0
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU:=textutils/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/textutils/textutils.html

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-prefix=g

USE_GMAKE=	yes

post-install:
	install-info ${PREFIX}/info/textutils.info ${PREFIX}/info/dir

.include "../../mk/bsd.pkg.mk"
.if ${OPSYS} == "SunOS"
PLIST_SUBST+=	LOCALEBASE=lib
.else
PLIST_SUBST+=	LOCALEBASE=share
.endif
