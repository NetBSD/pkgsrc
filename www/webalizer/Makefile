# $NetBSD: Makefile,v 1.20.2.1 2002/06/30 06:24:36 jlam Exp $
#

DISTNAME=	webalizer-2.01-09-src
PKGNAME=	webalizer-2.1.9
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://webalizer.dexa.org/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mrunix.net/webalizer/
COMMENT=	Web server log file analysis program

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}

USE_BUILDLINK2=		YES
USE_X11=		YES
GNU_CONFIGURE=  	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-dns
CONFIGURE_ENV+=		ac_cv_GDLIB=${BUILDLINK_PREFIX.gd}/include

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/webalizer.conf.sample ${PKG_SYSCONFDIR}/webalizer.conf

post-build:
	cd ${WRKSRC}; for file in sample.conf webalizer.1; do		\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f ${WRKSRC}/$${file}.fixed ${WRKSRC}/$${file};	\
	done

.include "../../graphics/gd/buildlink2.mk"

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
