# $NetBSD: Makefile,v 1.21 2022/06/28 11:37:50 wiz Exp $

DISTNAME=	squidclamav-6.16
PKGREVISION=	6
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=squidclamav/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://squidclamav.darold.net/
COMMENT=	Clamav ICAP service and redirector for Squid
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	clamav>=0.97:../../security/clamav
DEPENDS+=	squid>=3.1.12:../../www/squid4

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		perl
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-c-icap=${BUILDLINK_PREFIX.c-icap}

REPLACE_PERL=		cgi-bin/*

EGDIR=		${PREFIX}/share/squidclamav
CONF_FILES=	${EGDIR}/squidclamav.conf.default ${PKG_SYSCONFDIR}/squidclamav.conf

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Fixing config path.
SUBST_FILES.fix-cfg=	configure
SUBST_SED.fix-cfg=	-e 's,CFGDIR=/etc,CFGDIR=${PKG_SYSCONFDIR},'

.include "../../www/c-icap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
