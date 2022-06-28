# $NetBSD: Makefile,v 1.17 2022/06/28 11:37:41 wiz Exp $

DISTNAME=	Rose-HTMLx-Form-Field-Autocomplete-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Rose::HTMLx::Form::Field::Autocomplete
COMMENT=	Ajax autocompletion for text fields

DEPENDS+=	p5-Rose-HTML-Objects>=0.01:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Field/Autocomplete/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
