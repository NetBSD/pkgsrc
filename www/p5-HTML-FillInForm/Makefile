# $NetBSD: Makefile,v 1.9 2003/07/22 04:14:30 martti Exp $

DISTNAME=	HTML-FillInForm-0.29
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5hfi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module that populates HTML Forms with CGI data

DEPENDS+=	p5-HTML-Parser>=3.08:../../www/p5-HTML-Parser

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/FillInForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
