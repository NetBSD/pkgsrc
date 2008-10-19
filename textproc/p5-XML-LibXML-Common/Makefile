# $NetBSD: Makefile,v 1.14 2008/10/19 19:18:59 he Exp $
#

DISTNAME=	XML-LibXML-Common-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
SVR4_PKGNAME=	p5xlc
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML-Common/
COMMENT=	Routines and constants common for XML::LibXML and XML::GDOME

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/XML/LibXML/Common/.packlist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
