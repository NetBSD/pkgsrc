# $NetBSD: Makefile,v 1.11 2002/09/20 12:00:50 jlam Exp $

DISTNAME=	quanta-2.0-pr2
PKGNAME=	quanta-1.9.9.2
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quanta/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://quanta.sourceforge.net/
COMMENT= 	HTML editor suitable for experienced web developers

BUILD_DEPENDS+=	qt2-designer-kde>=2.3.1nb2:../../x11/qt2-designer-kde
BUILD_DEPENDS+=	automake>=1.4:../../devel/automake

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK2=		YES

USE_PERL5=		build
USE_GMAKE=              YES
GNU_CONFIGURE=          YES
USE_LIBTOOL=            YES
LTCONFIG_OVERRIDE=      ${WRKSRC}/admin/ltconfig

WRKSRC=		${WRKDIR}/quanta

pre-configure:
	cd ${WRKSRC};							\
	${LOCALBASE}/bin/aclocal;					\
	${LOCALBASE}/bin/autoheader;					\
	${LOCALBASE}/bin/autoreconf --force;				\
	${LOCALBASE}/bin/automake -a --gnu -i;				\
	${PERL5} admin/am_edit

.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdebase2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
