# $NetBSD: Makefile,v 1.13 2019/06/30 20:17:43 nia Exp $

DISTNAME=	Rose-HTMLx-Form-Field-Serial-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Rose-HTMLx-Form-Field-Serial
COMMENT=	Represent auto-increment columns in a form

DEPENDS+=	p5-Rose-HTML-Objects>=0:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Field/Serial/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
