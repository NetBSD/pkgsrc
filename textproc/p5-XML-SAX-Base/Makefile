# $NetBSD: Makefile,v 1.1.1.1 2008/11/28 14:32:55 he Exp $

DISTNAME=	XML-SAX-Base-1.02
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-SAX-Base/
COMMENT=	Base class SAX Drivers and Filters

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

#MAKE_ENV=	SKIP_SAX_INSTALL=yes
#EGSUBDIR=	share/examples/p5-XML-SAX
#CONF_FILES=	${EGSUBDIR}/ParserDetails.ini \
#			${PERL5_INSTALLVENDORLIB}/XML/SAX/ParserDetails.ini

PERL5_PACKLIST=	auto/XML/SAX/Base/.packlist

#INSTALLATION_DIRS+=	${EGSUBDIR}

#post-install:
#	${ECHO} > ${DESTDIR:Q}${PREFIX:Q}/${EGSUBDIR}/ParserDetails.ini

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
