# $NetBSD: Makefile,v 1.14 2011/08/14 15:14:21 obache Exp $

DISTNAME=	XML-UM-0.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=
PKGREVISION=	7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-UM-0.01/
COMMENT=	Convert UTF-8 strings to any encoding supported by XML::Encoding

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Encoding>=1.01:../../textproc/p5-XML-Encoding

PERL5_PACKLIST=	auto/XML/UM/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
