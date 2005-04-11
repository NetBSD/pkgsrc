# $NetBSD: Makefile,v 1.34 2005/04/11 21:48:02 tv Exp $
#

DISTNAME=	webalizer-2.01-10-src
PKGNAME=	webalizer-2.1.10
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.mrunix.net/pub/webalizer/ \
		ftp://webalizer.dexa.org/pub/webalizer/ \
		http://gd.tuwien.ac.at/infosys/logeval/webalizer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mrunix.net/webalizer/
COMMENT=	Web server log file analysis program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

WRKSRC=			${WRKDIR}/${DISTNAME:S/-src//}
USE_PKGINSTALL=		YES
GNU_CONFIGURE=  	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--enable-dns
CONFIGURE_ENV+=		ac_cv_GDLIB=${BUILDLINK_PREFIX.gd}/include

EGDIR=		${PREFIX}/share/examples
CONF_FILES=	${EGDIR}/webalizer.conf.sample ${PKG_SYSCONFDIR}/webalizer.conf

INSTALLATION_DIRS=	bin man/man1 share/examples

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"

post-build:
	cd ${WRKSRC}; for file in sample.conf webalizer.1; do		\
		${SED}	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"	\
			$${file} > $${file}.fixed;			\
		${MV} -f ${WRKSRC}/$${file}.fixed ${WRKSRC}/$${file};	\
	done

.include "../../mk/bsd.pkg.mk"
