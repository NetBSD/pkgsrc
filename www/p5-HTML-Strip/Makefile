# $NetBSD: Makefile,v 1.11 2014/11/19 14:57:17 wen Exp $

DISTNAME=	HTML-Strip-2.01
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Strip/
COMMENT=	Perl5 module for strip HTML tag

WRKSRC=	${WRKDIR}/HTML-Strip

PERL5_PACKLIST=	auto/HTML/Strip/.packlist

.include "../../textproc/icu/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
