# $NetBSD: Makefile,v 1.29 2014/05/29 23:38:05 wiz Exp $

DISTNAME=	HTML-FillInForm-2.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5hfi
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-FillInForm/
COMMENT=	Perl5 module that populates HTML Forms with CGI data
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser

PERL5_PACKLIST=		auto/HTML/FillInForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
