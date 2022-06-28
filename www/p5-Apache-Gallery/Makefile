# $NetBSD: Makefile,v 1.78 2022/06/28 11:37:08 wiz Exp $

DISTNAME=	Apache-Gallery-1.0.2-withoutworldwriteables
PKGNAME=	${DISTNAME:C/-without.*//}
PKGREVISION=	5
CATEGORIES=	graphics www
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/L/LE/LEGART/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Apache::Gallery
COMMENT=	Perl5/Apache module for handling image directories
LICENSE=	artistic

DEPENDS+=	p5-Image-Imlib2-[0-9]*:../../graphics/p5-Image-Imlib2
DEPENDS+=	p5-Image-Info-[0-9]*:../../graphics/p5-Image-Info
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-Text-Template-[0-9]*:../../textproc/p5-Text-Template
DEPENDS+=	p5-HTTP-Date-[0-9]*:../../www/p5-HTTP-Date
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

USE_LANGUAGES=	# none

TEST_ENV+=	MOD_PERL_API_VERSION=2
BUILD_DEFS+=	VARBASE

PERL5_PACKLIST=	auto/Apache/Gallery/.packlist

SUBST_CLASSES+=		var
SUBST_FILES.var+=	t/004_cache_dir.t
SUBST_SED.var+=		-e 's,/var/tmp/Apache-Gallery,${VARBASE}/cache/www,'
SUBST_STAGE.var=	pre-configure

.include "../../lang/perl5/module.mk"
# for make test
# (still asking for Apache::FakeRequest)
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
