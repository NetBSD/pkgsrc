# $NetBSD: Makefile,v 1.28 2003/07/17 22:56:07 grant Exp $
#

DISTNAME=	webalizer-2.01-10-src
PKGNAME=	webalizer-2.1.10
PKGREVISION=	1
WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://webalizer.dexa.org/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mrunix.net/webalizer/
COMMENT=	Web server log file analysis program

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
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

.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
