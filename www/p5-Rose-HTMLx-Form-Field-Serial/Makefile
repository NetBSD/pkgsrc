# $NetBSD: Makefile,v 1.16 2021/05/24 19:55:49 wiz Exp $

DISTNAME=	Rose-HTMLx-Form-Field-Serial-0.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
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
