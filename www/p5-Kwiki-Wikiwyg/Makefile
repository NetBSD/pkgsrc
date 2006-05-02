# $NetBSD: Makefile,v 1.1.1.1 2006/05/02 14:18:43 jlam Exp $

DISTNAME=      	Kwiki-Wikiwyg-0.13
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Kwiki/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.wikiwyg.net/
COMMENT=	Kwiki plugin for WYSIWYG editing

DEPENDS+=	p5-Kwiki>=0.38:../../www/p5-Kwiki

PERL5_PACKLIST=	auto/Kwiki/Wikiwyg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
