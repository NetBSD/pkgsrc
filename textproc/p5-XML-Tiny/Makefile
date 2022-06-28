# $NetBSD: Makefile,v 1.15 2022/06/28 11:36:45 wiz Exp $

DISTNAME=	XML-Tiny-2.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Tiny
COMMENT=	Simple lightweight parser for a subset of XML
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/XML/Tiny/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
