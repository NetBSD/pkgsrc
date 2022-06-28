# $NetBSD: Makefile,v 1.42 2022/06/28 11:37:21 wiz Exp $

DISTNAME=	HTML-FillInForm-2.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-FillInForm
COMMENT=	Perl5 module that populates HTML Forms with CGI data
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Parser>=3.26:../../www/p5-HTML-Parser

PERL5_PACKLIST=		auto/HTML/FillInForm/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
