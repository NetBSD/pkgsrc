# $NetBSD: Makefile,v 1.16 2006/02/20 11:15:49 hiramatsu Exp $

DISTNAME=	libapreq2-2.07
PKGNAME=	p5-libapreq2-2.07
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

.include "../../lang/perl5/module.mk"

MAKE_PARAMS:=	${MAKE_PARAMS:NINSTALLDIRS=vendor}
MAKE_PARAMS+=	--with-apache2-apxs="${APXS}" --with-mm-opts="INSTALLDIRS=vendor"

#pre-configure:
#	cd ${WRKSRC} && ./buildconf

.include "../../www/ap2-perl/buildlink3.mk"
.include "../../www/apache2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
