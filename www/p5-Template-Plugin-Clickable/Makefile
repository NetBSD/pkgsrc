# $NetBSD: Makefile,v 1.17 2022/06/28 11:37:43 wiz Exp $

DISTNAME=	Template-Plugin-Clickable-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-Plugin-Clickable
COMMENT=	TT2 plugin to make URLs clickable in HTML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Template-Toolkit>=2.07:../../www/p5-Template-Toolkit
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI-Find>=0.13:../../www/p5-URI-Find

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Template/Plugin/Clickable/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
