# $NetBSD: Makefile,v 1.11 2011/08/14 16:05:40 obache Exp $

DISTNAME=	dansguardian-${VERSION}.source
PKGNAME=	dansguardian-${VERSION}
VERSION=	2.8.0.6
PKGREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://dansguardian.org/downloads/2/Stable/

MAINTAINER=	sborrill@NetBSD.org
HOMEPAGE=	http://dansguardian.org/
COMMENT=	Fast, featureful web content filter for Squid proxy servers

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/dansguardian-${VERSION}
HAS_CONFIGURE=	yes
MANCOMPRESSED=	yes
RCD_SCRIPTS+=	dansguardian

BUILD_DEFS+=	VARBASE

PKG_SYSCONFSUBDIR=	dansguardian

EGDIR=		${PREFIX}/share/examples/dansguardian

SUBST_CLASSES+=		egconfpath
SUBST_STAGE.egconfpath=	pre-configure
SUBST_MESSAGE.egconfpath=	Setting example configuration path
SUBST_FILES.egconfpath=	autoconf/*.in
SUBST_SED.egconfpath=	-e 's,\$$(CONFFILELOCATION),${EGDIR}/,g'
SUBST_SED.egconfpath+=	-e '/SYSVLOCATION/d'
SUBST_SED.egconfpath+=	-e '/chmod.*dansguardian.pl/s,o\+x,+x,'

SUBST_CLASSES+=		perlpath
SUBST_STAGE.perlpath=	pre-configure
SUBST_MESSAGE.perlpath=	Fixing path to perl executable
SUBST_FILES.perlpath=	*.pl
SUBST_SED.perlpath=	-e 's,/usr/bin,${PREFIX}/bin,g'

DANSGUARDIAN_USER?=	dansgrdn
DANSGUARDIAN_GROUP?=	dansgrdn

PKG_USERS_VARS+=		DANSGUARDIAN_USER
PKG_GROUPS_VARS+=		DANSGUARDIAN_GROUP

PKG_GROUPS=			${DANSGUARDIAN_GROUP}
PKG_USERS=			${DANSGUARDIAN_USER}:${DANSGUARDIAN_GROUP}
PKG_GECOS.${DANSGUARDIAN_USER}=	Dansguardian webfilter pseudo-user

INSTALLATION_DIRS=	sbin libexec/cgi-bin ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/dansguardian/phraselists
INSTALLATION_DIRS+=	share/examples/dansguardian/languages

CONFIGURE_ARGS=		--prefix=${PREFIX:Q} \
			--cgidir=/libexec/cgi-bin/ \
			--sysconfdir=/etc/dansguardian/ \
			--bindir=/sbin/ \
			--mandir=/man/ \
			--installprefix=${DESTDIR:Q} \
			--runas_usr=${DANSGUARDIAN_USER} \
			--runas_grp=${DANSGUARDIAN_GROUP} \
			--logdir=${VARBASE}/log/dansguardian/

OWN_DIRS+=		${VARBASE}/log/dansguardian
OWN_DIRS_PERMS+=	${VARBASE}/log/dansguardian \
			${DANSGUARDIAN_USER} ${DANSGUARDIAN_GROUP} 0755

.for f in logrotation pics transparent1x1.gif \
	dansguardian.conf	\
	dansguardianf1.conf	\
	bannedextensionlist	\
	bannediplist	\
	bannedmimetypelist	\
	bannedphraselist	\
	bannedregexpurllist	\
	bannedsitelist	\
	bannedurllist	\
	banneduserlist	\
	contentregexplist	\
	exceptioniplist	\
	exceptionphraselist	\
	exceptionsitelist	\
	exceptionurllist	\
	exceptionuserlist	\
	filtergroupslist	\
	greysitelist	\
	greyurllist	\
	weightedphraselist	\
	phraselists/badwords/weighted_dutch	\
	phraselists/badwords/weighted_french	\
	phraselists/badwords/weighted_german	\
	phraselists/badwords/weighted_portuguese	\
	phraselists/badwords/weighted_spanish	\
	phraselists/chat/weighted	\
	phraselists/chat/weighted_italian	\
	phraselists/drugadvocacy/weighted	\
	phraselists/gambling/banned	\
	phraselists/gambling/banned_portuguese	\
	phraselists/gambling/weighted	\
	phraselists/gambling/weighted_portuguese	\
	phraselists/games/weighted	\
	phraselists/goodphrases/exception	\
	phraselists/goodphrases/exception_email	\
	phraselists/goodphrases/weighted_general	\
	phraselists/goodphrases/weighted_general_danish	\
	phraselists/goodphrases/weighted_general_portuguese	\
	phraselists/goodphrases/weighted_news	\
	phraselists/googlesearches/banned	\
	phraselists/gore/weighted	\
	phraselists/gore/weighted_portuguese	\
	phraselists/illegaldrugs/banned	\
	phraselists/illegaldrugs/banned_portuguese	\
	phraselists/illegaldrugs/weighted	\
	phraselists/illegaldrugs/weighted_portuguese	\
	phraselists/intolerance/banned_portuguese	\
	phraselists/intolerance/weighted	\
	phraselists/intolerance/weighted_portuguese	\
	phraselists/legaldrugs/weighted	\
	phraselists/malware/weighted	\
	phraselists/news/weighted	\
	phraselists/nudism/weighted	\
	phraselists/peer2peer/weighted	\
	phraselists/personals/weighted	\
	phraselists/personals/weighted_portuguese	\
	phraselists/pornography/banned	\
	phraselists/pornography/banned_portuguese	\
	phraselists/pornography/weighted	\
	phraselists/pornography/weighted_danish	\
	phraselists/pornography/weighted_dutch	\
	phraselists/pornography/weighted_french	\
	phraselists/pornography/weighted_german	\
	phraselists/pornography/weighted_italian	\
	phraselists/pornography/weighted_portuguese	\
	phraselists/pornography/weighted_spanish	\
	phraselists/proxies/weighted	\
	phraselists/sport/weighted	\
	phraselists/violence/weighted	\
	phraselists/violence/weighted_portuguese	\
	phraselists/warezhacking/weighted	\
	phraselists/weapons/weighted	\
	phraselists/weapons/weighted_portuguese	\
	phraselists/webmail/weighted	\
	languages/ReadMe
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

PHRASEDIRS=	badwords chat drugadvocacy gambling games \
		goodphrases googlesearches gore illegaldrugs \
		intolerance legaldrugs malware news nudism \
		peer2peer personals pornography proxies sport \
		violence warezhacking weapons webmail

LANGUAGEDIRS=	arspanish bulgarian chinesebig5 chinesegb2312 \
		czech danish dutch french german hebrew \
		indonesian italian lithuanian mxspanish polish \
		portuguese russian-1251 slovak spanish \
		swedish turkish ukenglish

.for d in ${PHRASEDIRS}
OWN_DIRS+=	${PKG_SYSCONFDIR}/phraselists/${d}
INSTALLATION_DIRS+=	share/examples/dansguardian/phraselists/${d}
.endfor

.for d in ${LANGUAGEDIRS}
OWN_DIRS+=	${PKG_SYSCONFDIR}/languages/${d}
CONF_FILES+=	${EGDIR}/languages/${d}/messages \
		${PKG_SYSCONFDIR}/languages/${d}/messages
CONF_FILES+=	${EGDIR}/languages/${d}/template.html \
		${PKG_SYSCONFDIR}/languages/${d}/template.html
INSTALLATION_DIRS+=	share/examples/dansguardian/languages/${d}
.endfor

show-conffiles:
	cd ${WRKSRC}; 				\
	for file in *.conf *list;		\
	do \
		${PRINTF} "\\t$${file}\\t\\\\\\n"; \
	done; \
	for dir in phraselists/* languages/*; \
	do \
		if [ -d $${dir} ];  then  \
			for file in $${dir}/*; \
			do \
				${PRINTF} "\\t$${file}\\t\\\\\\n"; \
			done; \
		else \
			${PRINTF} "\\t$${dir}\\t\\\\\\n"; \
		fi; \
	done

USE_LANGUAGES=	c c++

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
