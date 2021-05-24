# $NetBSD: Makefile,v 1.26 2021/05/24 19:55:53 wiz Exp $

DISTNAME=	URI-Escape-XS-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	www net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=URI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/URI-Escape-XS
COMMENT=	Escape and unescape unsafe characters in URIs
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-URI>=1.35:../../www/p5-URI

PERL5_PACKLIST=	auto/URI/Escape/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
