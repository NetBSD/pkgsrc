# $NetBSD: Makefile,v 1.8 2005/12/17 05:20:23 jlam Exp $

DISTNAME=      	Kwiki-0.38
PKGNAME=       	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.kwiki.org/
COMMENT=	Extensible, modular, Perl-based Wiki

DEPENDS+=	p5-Spoon>=0.21nb1:../../devel/p5-Spoon

PERL5_PACKLIST=		auto/Kwiki/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
