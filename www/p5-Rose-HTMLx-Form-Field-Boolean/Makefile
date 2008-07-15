# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 08:44:04 abs Exp $

DISTNAME=	Rose-HTMLx-Form-Field-Boolean-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Rose::HTMLx::Form::Field::Boolean
COMMENT=	Extend Rose::HTML::Objects RadioButtonGroup

DEPENDS+=	p5-Rose-HTML-Objects>=0.01:../../www/p5-Rose-HTML-Objects

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Rose/HTMLx/Form/Field/Boolean/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
