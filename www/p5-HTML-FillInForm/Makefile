# $NetBSD: Makefile,v 1.11 2004/04/25 05:49:52 minskim Exp $

DISTNAME=	HTML-FillInForm-1.03
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hfi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module that populates HTML Forms with CGI data

DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/FillInForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
