# $NetBSD: Makefile,v 1.1 2026/01/31 03:10:44 wen Exp $

DISTNAME=	Test2-MojoX-0.07
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EL/ELCAMLOST/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://mojolicio.us/
COMMENT=	Testing Mojo
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Mojolicious-[0-9]*:../../www/p5-Mojolicious

TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test2/MojoX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
