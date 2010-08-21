# $NetBSD: Makefile,v 1.3 2010/08/21 16:37:04 seb Exp $

DISTNAME=	Rose-HTMLx-Form-Field-Autocomplete-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Rose::HTMLx::Form::Field::Autocomplete
COMMENT=	Ajax autocompletion for text fields

DEPENDS+=	p5-Rose-HTML-Objects>=0.01:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Field/Autocomplete/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
