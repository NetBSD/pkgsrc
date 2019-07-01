# $NetBSD: Makefile,v 1.13 2019/07/01 21:36:00 nia Exp $

DISTNAME=	Rose-HTMLx-Form-Field-Boolean-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Rose::HTMLx::Form::Field::Boolean
COMMENT=	Extend Rose::HTML::Objects RadioButtonGroup

DEPENDS+=	p5-Rose-HTML-Objects>=0.01:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Field/Boolean/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
