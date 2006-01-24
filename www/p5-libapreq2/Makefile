# $NetBSD: Makefile,v 1.14 2006/01/24 07:32:50 wiz Exp $

DISTNAME=	libapreq2-2.06-dev
PKGNAME=	p5-libapreq2-2.06
PKGREVISION=	2
SVR4_PKGNAME=	p5la2
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_APACHE:=httpd/libapreq/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	p5-ExtUtils-XSBuilder>=0.23:../../devel/p5-ExtUtils-XSBuilder

BUILDLINK_DEPENDS.apache+=	apache>=2.0.48
BUILDLINK_DEPENDS.ap2-perl+=	ap2-perl>=2.0.1

USE_TOOLS+=	gmake
USE_LIBTOOL=	YES
PERL5_PACKLIST=	auto/libapreq2/.packlist

SUBST_CLASSES+=		apxs
SUBST_STAGE.apxs=	post-patch
SUBST_FILES.apxs=	env/Makefile.in
SUBST_SED.apxs=		-e "s|@APACHE2_APXS@ -i -a -n|@APACHE2_APXS@ -i -n|g"
SUBST_MESSAGE.apxs=	"Fixing module installation."

MAKE_PARAMS+=	--with-apache2-apxs="${APXS}"

#pre-configure:
#	cd ${WRKSRC} && ./buildconf

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
