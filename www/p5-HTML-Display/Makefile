# $NetBSD: Makefile,v 1.9 2021/05/24 19:55:30 wiz Exp $

DISTNAME=	HTML-Display-0.40
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Display
COMMENT=	Display HTML locally in a browser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI>=0.0:../../www/p5-URI
DEPENDS+=	p5-libwww>=5.69:../../www/p5-libwww
DEPENDS+=	p5-HTML-TokeParser-Simple>=2:../../www/p5-HTML-TokeParser-Simple

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	MakeMaker
PERL5_PACKLIST=		auto/HTML/Display/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
