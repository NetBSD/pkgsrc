# $NetBSD: Makefile,v 1.12 2004/12/05 18:25:43 he Exp $

DISTNAME=	HTML-FillInForm-1.04
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hfi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-FillInForm/
COMMENT=	Perl5 module that populates HTML Forms with CGI data

DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/FillInForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
